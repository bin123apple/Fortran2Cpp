program test
  call test_sub()
contains
  subroutine test_sub()
    call sub()
    ! Assuming sub does something in the future, verify its behavior here
    print *, 'sub executed successfully'
  end subroutine test_sub

  subroutine sub()
    ! Future functionality goes here
  end subroutine sub
end program test