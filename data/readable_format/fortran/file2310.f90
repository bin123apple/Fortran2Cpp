program test_translation
  implicit none
  integer, dimension(3) :: i = (/1, 2, 3/)
  integer, dimension(3) :: expected = (/3, 4, 6/)
  logical :: passed

  call modify_array(i)
  passed = all(i == expected)

  if (passed) then
    print *, "Test passed."
  else
    print *, "Test failed. Result:"
    print *, i
  end if

contains

  subroutine modify_array(i)
    integer, dimension(3) :: i
    where (i > 1)
      i = i * 2
    elsewhere
      i = i * 3
    endwhere
  end subroutine modify_array

end program test_translation