module ast_obs_module
    implicit none

    TYPE ast_obs
        real, DIMENSION(:), POINTER :: geopos
    END TYPE ast_obs

    TYPE(ast_obs), PARAMETER :: undefined_ast_obs = AST_OBS(NULL())

contains

    SUBROUTINE get_null_ast_obs (obs1)
        TYPE(ast_obs), intent(inout) :: obs1
        obs1 = undefined_ast_obs
    END SUBROUTINE get_null_ast_obs

    SUBROUTINE test_ast_obs()
        type(ast_obs) :: my_ast_obs
        real, target, dimension(10) :: rt
        my_ast_obs%geopos => rt
        if (.not.associated (my_ast_obs%geopos)) stop "Test 1 Failed"

        call get_null_ast_obs (my_ast_obs)
        if (associated (my_ast_obs%geopos)) stop "Test 2 Failed"

        print *, "All Fortran tests passed."
    END SUBROUTINE test_ast_obs

end module ast_obs_module

program test
    use ast_obs_module
    call test_ast_obs()
end program test