program DRB050_functionparameter_orig_no
    use omp_lib
    use DRB050
    implicit none

    allocate (o1(100))
    allocate (c(100))

    call foo1(o1, c, 100)
end program
