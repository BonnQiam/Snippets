#? This file is modified version of autograd/integrate.py
#? This file work with 'ivp_SciPy.py' which is modified version of 'ivp.py'
#? The purpose of this file is to using 'solve_ivp' instead of 'odeint'

from __future__ import absolute_import
from builtins import range

import scipy.integrate

import autograd.numpy as np
from autograd.extend import primitive, defvjp_argnums
from autograd import make_vjp
from autograd.misc import flatten
from autograd.builtins import tuple

##!odeint = primitive(scipy.integrate.odeint)
odeint = primitive(scipy.integrate.solve_ivp)

#? t = [t_0, t_1, ..., t_n] in odeint
#? t = [t_0, t_n] in solve_ivp

def grad_odeint(yt, func, t, y0, func_args, **kwargs):
#!def grad_odeint(yt, func, y0, t, func_args, **kwargs):
    # Extended from "Scalable Inference of Ordinary Differential
    # Equation Models of Biochemical Processes", Sec. 2.4.2
    # Fabian Froehlich, Carolin Loos, Jan Hasenauer, 2017
    # https://arxiv.org/abs/1711.08079
    
#!    T, D = np.shape(yt.y)
    D = len(yt)
    flat_args, unflatten = flatten(func_args)

    def flat_func(y, t, flat_args):
#!        return func(y, t, *unflatten(flat_args))
        return func(t, y, *unflatten(flat_args))

    def unpack(x):
#        print(x)
        #      y,      vjp_y,      vjp_t,    vjp_args
        return x[0:D], x[D:2 * D], x[2 * D], x[2 * D + 1:]

    def augmented_dynamics(t, augmented_state, flat_args):
#    def augmented_dynamics(augmented_state, t, flat_args):
        # Orginal system augmented with vjp_y, vjp_t and vjp_args.
        y, vjp_y, _, _ = unpack(augmented_state)
        vjp_all, dy_dt = make_vjp(flat_func, argnum=(0, 1, 2))(y, t, flat_args)
        vjp_y, vjp_t, vjp_args = vjp_all(-vjp_y)
        return np.hstack((dy_dt, vjp_y, vjp_t, vjp_args))

    def vjp_all(g):
        
        
#        print("============================")
#        print(g)
        
        time_vjp_list = []
        
        vjp_y = g
        
        vjp_cur_t = np.dot(func(t[1], yt, *func_args), g)
        
        time_vjp_list.append(vjp_cur_t)
        
        vjp_t0 = - vjp_cur_t
#        print(vjp_t0)
        
        vjp_args = np.zeros(np.size(flat_args)) # a_theta(t_n)
        
        aug_y0 = np.hstack((yt, vjp_y, vjp_t0, vjp_args))
#        print(D)
#        print(aug_y0)
#        print("=====================================")
        aug_ans = odeint(augmented_dynamics, t[::-1], aug_y0, tuple((flat_args,)), **kwargs)        
        
        tmp, vjp_y, vjp_t0, vjp_args = unpack(aug_ans)
        
#        print(aug_ans)
#        print(tmp)
#        print(vjp_y)
#        print(vjp_t0)
#        print(vjp_args)
        
        # Add gradient from current output.
#!        vjp_y = vjp_y + g[- 1, :]
        
        time_vjp_list.append(vjp_t0)
        vjp_times = np.hstack(time_vjp_list)[::-1]
#        vjp_times = np.hstack(time_vjp_list)
        
#        print(vjp_times)
#        print("============================")
        
#        return None, vjp_y, vjp_times, unflatten(vjp_args)
        return None, vjp_times, vjp_y, unflatten(vjp_args)
    return vjp_all
        
"""        
        #####################################################################

        vjp_y = g[-1, :] # a(t_n)
        vjp_t0 = 0       
        time_vjp_list = []
        vjp_args = np.zeros(np.size(flat_args)) # a_theta(t_n)
        
        for i in range(T - 1, 0, -1): # integrate in t_i, t_{i-1}

            # Compute effect of moving measurement time.
            vjp_cur_t = np.dot(func(yt[i, :], t[i], *func_args), g[i, :])
            time_vjp_list.append(vjp_cur_t)
            vjp_t0 = vjp_t0 - vjp_cur_t

            # Run augmented system backwards to the previous observation.
            aug_y0 = np.hstack((yt[i, :], vjp_y, vjp_t0, vjp_args)) 
            aug_ans = odeint(augmented_dynamics, aug_y0,
                             np.array([t[i], t[i - 1]]), tuple((flat_args,)), **kwargs)
            _, vjp_y, vjp_t0, vjp_args = unpack(aug_ans[1])

            # Add gradient from current output.
            vjp_y = vjp_y + g[i - 1, :]

        time_vjp_list.append(vjp_t0)
        vjp_times = np.hstack(time_vjp_list)[::-1]

        return None, vjp_y, vjp_times, unflatten(vjp_args)
    return vjp_all
"""


def argnums_unpack(all_vjp_builder):
    # A generic autograd helper function.  Takes a function that
    # builds vjps for all arguments, and wraps it to return only required vjps.
    def build_selected_vjps(argnums, ans, combined_args, kwargs):
        vjp_func = all_vjp_builder(ans, *combined_args, **kwargs)

        def chosen_vjps(g):  # Returns whichever vjps were asked for.
#            print("======================================================")
#            print("argnums = ", argnums)
            all_vjps = vjp_func(g)
#            print(all_vjps)
            return [all_vjps[argnum] for argnum in argnums]
        return chosen_vjps
    return build_selected_vjps

defvjp_argnums(odeint, argnums_unpack(grad_odeint))
