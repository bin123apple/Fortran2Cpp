subroutine defcolor(icolor)

  implicit none
  integer :: icolor
  character*7 colors(8)
  character*7 selectedColor

  colors(1) = 'white  '
  colors(2) = 'red    '
  colors(3) = 'cyan   '
  colors(4) = 'yellow '
  colors(5) = 'green  '
  colors(6) = 'magenta'
  colors(7) = 'blue   '
  colors(8) = 'black  '

  if (icolor >= 1 .and. icolor <= 8) then
    selectedColor = colors(icolor)
    print *, 'Selected color is:', selectedColor
  else
    print *, 'Invalid color index'
  end if

end subroutine defcolor

program testDefColor
  call defcolor(1)
  call defcolor(5)
  call defcolor(9)
end program testDefColor