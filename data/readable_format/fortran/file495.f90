! File: test_module_geometry.f90
module module_geometry
    implicit none

    integer :: Nnco, Nnco0, Nncoold
    integer :: Npf, Npb, Npo
    integer :: Nsamp, Nsampold
    double precision :: Ls, Ls0, Lsold   
    double precision :: Lx, Lx0, Lxold   

    integer, allocatable :: oxrow(:), oxsum(:)      
    integer, allocatable :: pbrow(:), pbsum(:)      
    integer, allocatable :: whereisnode(:)          

    double precision, allocatable :: x(:), y(:), x0(:), y0(:) 
    double precision, allocatable :: xo(:), yo(:)             
    double precision, allocatable :: xb(:), yb(:)             
    double precision, allocatable :: s(:)                     
    double precision, allocatable :: th(:)                    
    double precision, allocatable :: c(:)                     
    double precision, allocatable :: dU(:)                    
    double precision, allocatable :: E(:)                     
end module module_geometry

program test_geometry
    use module_geometry
    implicit none
    integer :: i

    ! Allocate arrays
    allocate(oxrow(10), oxsum(10))
    allocate(x(10), y(10))

    ! Initialize some variables
    Nnco = 5
    Ls = 3.14

    ! Initialize arrays
    oxrow = (/ (i, i = 1, 10) /)
    x = (/ (0.1*real(i), i = 1, 10) /)

    ! Print variables and array elements
    print *, "Nnco:", Nnco
    print *, "Ls:", Ls
    print *, "oxrow:", oxrow
    print *, "x:", x

    ! Deallocate arrays
    deallocate(oxrow, oxsum)
    deallocate(x, y)
end program test_geometry