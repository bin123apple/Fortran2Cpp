program DRB068_restrictpointer2_orig_no
    use omp_lib
    use DRB068
    implicit none

    integer :: n = 1000
    integer, dimension(:), pointer :: a=>null(), b=>null(), c=>null(), d=>null()

    allocate (a(n))
    allocate (b(n))
    allocate (c(n))
    allocate (d(n))

    call foo(n,a,b,c,d)

    if(associated(a))nullify(a)
    if(associated(b))nullify(b)
    if(associated(c))nullify(c)
    if(associated(d))nullify(d)

end program
