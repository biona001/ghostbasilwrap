# ghostbasilwrap

This repo contains experimental code to call C++ from Julia. 
+ The intention is to create Julia wrapper for [ghostbasil's C++ routine](https://github.com/JamesYang007/ghostbasil) (currently not publically available) to be used in `GhostKnockoffGWAS.jl`. 
+ Ultimately, we want to make [GhostKnockoffGWAS.jl](https://github.com/biona001/GhostKnockoffGWAS) package entirely self-contained within Julia, so we can create binaries and Apps for easy usage. That is, we need to be able to install `ghostbasil` and use it directly within Julia. 

## Roadmap to creating an App for `GhostKnockoffGWAS.jl`

1. Create Julia wrappers for ghostbasil's C++ routine
    + High priority functions: `BlockMatrix`, `BlockGroupGhostMatrix`, `ghostbasil` (these are being used in `GhostKnockoffGWAS.jl`)
    + Mid priority functions: `quad_form` (this was previously used but not anymore)
    + Low priority functions: everything else
2. Use [BinaryBuilder.jl](https://github.com/JuliaPackaging/BinaryBuilder.jl) to create a `jll` package (e.g. `ghostbasil_jll.jl`) that enables usage of ghostbasil functions in Julia directly (this will require ghostbasil to be publically available)
3. Host this `jll` on [Yggdrasil](https://github.com/JuliaPackaging/Yggdrasil)
4. Use [PackageCompiler.jl](https://github.com/JuliaLang/PackageCompiler.jl) to bundle all source code (maybe also pre-computed knockoff statistics) into an [App](https://julialang.github.io/PackageCompiler.jl/stable/apps.html) which can be used by potentially users for re-analysis of GWAS summary statistics data. 
