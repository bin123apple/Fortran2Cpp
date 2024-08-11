program testWriteVector
    implicit none
    integer :: nums(3) = (/1, 2, 3/)
    real*8 :: vectors(3,3) = reshape((/1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0/), (/3,3/))
    integer :: i, j
    character(len=50) :: line

    ! Make sure to include or link your original writevector subroutine here.

    do i = 1, size(nums)
        call writevector(vectors(:,i), 3, nums(i))
        open(unit=20, file='vector_'//trim(adjustl(char(nums(i)+96)))//'.out', status='old')
        do j = 1, 4 + 3 ! Assuming header + number of rows
            read(20, '(A)') line
            print *, trim(adjustl(line))
        end do
        close(20)
    end do
end program testWriteVector

subroutine writevector(ad, neq, number)
    implicit none
    character(len=12) :: name
    integer :: neq, i, number
    real(8) :: ad(*)

    name = 'vector_' // char(iachar('a') + number - 1) // '.out'

    open(10, file=name, status='unknown')
    write(10, *) 'vector number ', number
    do i = 1, neq
        write(10, *) 'row ', i, ' value ', ad(i)
    end do
    close(10)
end subroutine writevector