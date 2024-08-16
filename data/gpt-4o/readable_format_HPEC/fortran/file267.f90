program DRB047_doallchar_orig_no
    use omp_lib
    implicit none

    character(len=100), dimension(:), allocatable :: a
    character(50) :: str
    integer :: i

    allocate (a(100))

    !$omp parallel do private(str)
    do i = 1, 100
        write( str, '(i10)' )  i
        a(i) = str
    end do
    !$omp end parallel do

    print*,'a(i)',a(23)
end program
