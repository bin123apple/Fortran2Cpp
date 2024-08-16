program DRB067_restrictpointer1_orig_no
    use omp_lib
    use DRB067
    implicit none

    integer :: len = 1000
    integer, parameter :: dp = kind(1.0d0)
    real(dp),dimension(:), pointer :: newSxx, newSyy

    allocate (newSxx(len))
    allocate (newSyy(len))

    call foo(newSxx, newSyy, len)

    if(associated(newSxx))nullify(newSxx)
    if(associated(newSyy))nullify(newSyy)
end program
