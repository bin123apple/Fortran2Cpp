program test_image_status
  use iso_fortran_env, only: STAT_STOPPED_IMAGE
  implicit none

  integer :: status
  integer, parameter :: STAT_OK = 0

  ! Test 1: Check if image 1 reports OK
  status = image_status(1)
  if (status /= STAT_OK) then
    print *, "Test 1 Failed: Image 1 should report OK. Status:", status
  else
    print *, "Test 1 Passed"
  end if

  ! Test 2: Check if image 2 is stopped
  status = image_status(2)
  if (status /= STAT_STOPPED_IMAGE) then
    print *, "Test 2 Failed: Image 2 should be stopped. Status:", status
  else
    print *, "Test 2 Passed"
  end if

  ! Test 3: Check if image 3 is stopped
  status = image_status(3)
  if (status /= STAT_STOPPED_IMAGE) then
    print *, "Test 3 Failed: Image 3 should be stopped. Status:", status
  else
    print *, "Test 3 Passed"
  end if

contains

  function image_status(image_id) result(status)
    integer, intent(in) :: image_id
    integer :: status

    select case(image_id)
    case(1)
      status = STAT_OK
    case(2, 3)
      status = STAT_STOPPED_IMAGE
    case default
      status = -1
    end select
  end function image_status

end program test_image_status