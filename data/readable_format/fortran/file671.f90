module test_block

contains

  subroutine suba(b_out)
    integer :: a
    integer, intent(out) :: b_out
    
    a = 5
    block
      integer :: b
      b = a + 2
      b_out = b
    end block
  end subroutine

  subroutine subb
  end subroutine

end module test_block

program test
  use test_block
  integer :: result
  
  call suba(result)
  print *, "Test for suba: ", (result == 7)
end program test