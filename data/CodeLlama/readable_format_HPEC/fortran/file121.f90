program DRB048_firstprivate_orig_no
    use omp_lib
    use DRB048
    implicit none

    allocate (a(100))
    call foo(a, 100, 7)
    print*,a(50)
end program
