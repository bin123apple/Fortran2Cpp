program testFixmap
  implicit none
  integer, parameter :: numel = 5
  integer :: map(numel) = [0, 2, 0, 4, 0]
  integer :: i
  
  call fixmap(numel, map)
  
  do i = 1, numel
    print *, 'map(', i, ') = ', map(i)
  end do

end program testFixmap

subroutine fixmap(numel, map)
  integer, intent(in) :: numel
  integer, intent(inout) :: map(numel)
  integer :: i
  
  do i = 1, numel
    if (map(i) == 0) then
      map(i) = i
    endif
  end do

end subroutine fixmap