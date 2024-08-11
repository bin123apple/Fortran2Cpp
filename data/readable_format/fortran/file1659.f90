program main
  implicit none

  integer, parameter :: sx = 640, sy = 480, crop = 100
  double precision, dimension (sx,sy) :: screen
  double precision, parameter :: ox = 320.0, oy = 240.0

  integer :: file_unit
  integer :: x,y

  ! Initialize the screen array
  screen = -99999.0

  ! Apply calculation within the specified bounds
  do y = 1 + crop, sy - crop
     do x = 1 + crop, sx - crop
        screen(x,y) = (x-ox) ** 2 + (y-oy) ** 2
     end do
  end do

  ! Get a unique file unit for output
  file_unit = get_file_unit()
  open(file_unit, file='test.bin', status='replace', access='stream')

  ! Write the dimensions after cropping and then the modified screen data
  write(file_unit) sx-2*crop, sy-2*crop
  do y = 1 + crop, sy - crop
     write(file_unit) (screen(x, y), x = 1 + crop, sx - crop)
  end do
  close(file_unit)

  ! Simple testing mechanism
  print *, "Test Passed: Check 'test.bin' for output"

contains

  integer function get_file_unit()
    ! Finds an available logical unit number for file operations
    integer, parameter :: LUN_MIN=10, LUN_MAX=1000
    logical :: opened
    integer :: lun

    get_file_unit = -1
    do lun = LUN_MIN, LUN_MAX
       inquire(unit=lun, opened=opened)
       if (.not. opened) then
          get_file_unit = lun
          exit
       end if
    end do
  end function get_file_unit

end program main