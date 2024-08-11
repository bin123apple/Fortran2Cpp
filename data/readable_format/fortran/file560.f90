program example_test
implicit none
integer :: i
open(unit=10, file='output.txt', status='replace', action='write')
do i = 1, 5
   write(10, *) "Value of i: ", i
end do
close(10)
end program example_test