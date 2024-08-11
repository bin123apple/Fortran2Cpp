program test_prog
    implicit none
    real, dimension(2) :: data
    integer, dimension(2) :: nums
    
    ! Initialize the arrays
    nums = [12, 34]
    data = [1.2, 3.4]

    ! Call the subroutine which performs the original program's operation
    call perform_operations(nums, data)
    
    ! Here you can add simple "tests" by checking the output manually,
    ! or by printing and manually verifying (due to Fortran's lack of a built-in unit testing framework).
    
end program test_prog

subroutine perform_operations(nums, data)
    implicit none
    real, intent(in) :: data(2)
    integer, intent(in) :: nums(2)
    
    ! Original program logic here...
    print '(f3.1,x,f3.1)', data
    print '(i3,x,i3)', nums

end subroutine perform_operations