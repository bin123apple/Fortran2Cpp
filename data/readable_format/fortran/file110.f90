module chtest
contains
  function chararray2string(chararray) result(text)
    character(len=1), dimension(:) :: chararray
    character(len=size(chararray)) :: text
    do i = 1,size(chararray)
      text(i:i) = chararray(i)
    end do
  end function chararray2string

  subroutine testChararray2string()
    character(len=1), dimension(2) :: testArray
    character(len=2) :: resultString
    
    ! Test case 1: Convert "AB" to a string
    testArray = ['A', 'B']
    resultString = chararray2string(testArray)
    if (resultString .ne. "AB") then
      print *, "Test Failed: AB"
    else
      print *, "Test Passed: AB"
    endif
  end subroutine testChararray2string
end module chtest

program TestStringTools
  use chtest
  call testChararray2string()
end program TestStringTools