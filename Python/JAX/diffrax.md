#Wiki

<center>
<iframe 
	border=0 
	frameborder=0 
	height=250 
	width=800
	src="https://github.com/patrick-kidger/diffrax"> 
</iframe>
</center>

> Numerical differential equation solvers in JAX / [[JAX]]. Autodifferentiable and GPU-capable.

Features include:
- ODE/SDE/CDE (ordinary/stochastic/controlled) solvers;
- lots of different solvers (including `Tsit5`, `Dopri8`, symplectic solvers, implicit solvers);
- vmappable _everything_ (including the region of integration);
- using a PyTree as the state;
- dense solutions;
- multiple adjoint methods for backpropagation; —— [[Adjoint Sensitivity Analysis]]
- support for neural differential equations.

_From a technical point of view, the internal structure of the library is pretty cool -- all kinds of equations (ODEs, SDEs, CDEs) are solved in a unified way (rather than being treated separately), producing a small tightly-written library._