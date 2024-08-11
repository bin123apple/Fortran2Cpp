module mod_parameters
     
     integer, parameter :: i64 = selected_int_kind(18)
     integer, parameter :: buffer_len = 100
     integer, parameter :: nhb = 400
     double precision, parameter :: a = 1.0d0
     double precision :: b
     character(len=1024) :: geometry
     
     double precision :: aratio, q, Pe, x0width, y0, z0, t_warmup, dt, dtmax, Tfinal
     integer :: nGates, x0n, nbins
     logical :: save_hist, save_hist2d, use_external_ic, use_oscillatory
     character(len=1024) :: ic_file, tstep_type, other_file
     
     integer(i64) :: mt_seed

end module mod_parameters

program test_mod_parameters
    use mod_parameters
    implicit none

    ! Test parameters
    if (buffer_len /= 100) then
        print *, "Test failed for buffer_len"
    endif

    if (nhb /= 400) then
        print *, "Test failed for nhb"
    endif

    if (a /= 1.0d0) then
        print *, "Test failed for a"
    endif

    ! Test modifiable variables
    b = 2.0d0
    if (b /= 2.0d0) then
        print *, "Test failed for b"
    endif

    print *, "All tests passed successfully"
end program test_mod_parameters