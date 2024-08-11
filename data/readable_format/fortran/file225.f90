program test_titles
  implicit none
  character(len=3) :: titles(18)
  integer :: i
  character(len=3), parameter :: expected_titles(18) = &
       ['SMA', 'PMA', 'SRA', 'PRA', 'PER', &
        'INC', 'EPO', 'ZPT', 'ALB', 'NL1', &
        'NL2', 'NL3', 'NL4', 'ECW', 'ESW', &
        'TED', 'VOF', 'DIL']

  ! Initialize titles array
  titles(1) = 'SMA'
  titles(2) = 'PMA'
  titles(3) = 'SRA'
  titles(4) = 'PRA'
  titles(5) = 'PER'
  titles(6) = 'INC'
  titles(7) = 'EPO'
  titles(8) = 'ZPT'
  titles(9) = 'ALB'
  titles(10) = 'NL1'
  titles(11) = 'NL2'
  titles(12) = 'NL3'
  titles(13) = 'NL4'
  titles(14) = 'ECW'
  titles(15) = 'ESW'
  titles(16) = 'TED'
  titles(17) = 'VOF'
  titles(18) = 'DIL'

  ! Testing each title against expected values
  do i = 1, 18
     if (titles(i) /= expected_titles(i)) then
        print *, 'Test failed at index:', i
        print *, 'Expected:', expected_titles(i), 'Got:', titles(i)
        stop
     endif
  enddo

  print *, 'All tests passed.'
end program test_titles