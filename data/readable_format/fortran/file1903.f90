program testLenoccProgram
  implicit none
  character*(20) testString1
  character*(3) testString2
  character*(8) testString3
  integer result

  testString1 = 'hello world  '
  testString2 = '   '
  testString3 = 'noSpaces'

  result = lenocc(testString1)
  write(*,*) 'Test 1:', result == 11
  result = lenocc(testString2)
  write(*,*) 'Test 2:', result == 0
  result = lenocc(testString3)
  write(*,*) 'Test 3:', result == 8

contains

  integer function lenocc(c)
    character*(*) c
    integer i

    lenocc = len(trim(c))
    do i = lenocc,1,-1
      if (c(i:i) .ne. ' ') then
        return
      endif
    end do
    lenocc = 0
  end function lenocc

end program testLenoccProgram