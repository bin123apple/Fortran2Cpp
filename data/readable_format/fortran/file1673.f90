module gtk_hl_accelerator
  implicit none
contains
  subroutine hl_gtk_widget_add_accelerator(widget, signal, accel_group, accel_key, accel_mods, accel_flags)
    integer, intent(in) :: widget, accel_group
    character(len=*), intent(in) :: signal, accel_key
    integer, intent(in), optional :: accel_mods, accel_flags
    integer :: ikey, imods, iflags

    ! Default values
    if (present(accel_mods)) then
       imods = accel_mods
    else
       imods = 4  ! Simulated GDK_CONTROL_MASK
    end if

    if (present(accel_flags)) then
       iflags = accel_flags
    else
       iflags = 1  ! Simulated GTK_ACCEL_VISIBLE
    end if

    ! Simulate key value conversion
    ikey = iachar(accel_key)

    ! Simulate adding accelerator
    print *, "Adding accelerator to widget", widget, "with key", accel_key
    print *, "Modifiers:", imods, "Flags:", iflags
  end subroutine hl_gtk_widget_add_accelerator
end module gtk_hl_accelerator

program test_accelerator
  use gtk_hl_accelerator
  implicit none

  ! Simulate widget and accel_group with integers
  integer :: widget, accel_group
  integer :: mods, flags
  character(len=1) :: key
  character(len=10) :: signal

  widget = 1
  accel_group = 1
  mods = 4           ! Simulated GDK_CONTROL_MASK
  flags = 1          ! Simulated GTK_ACCEL_VISIBLE
  key = 'A'
  signal = 'activate'

  call hl_gtk_widget_add_accelerator(widget, signal, accel_group, key, mods, flags)

end program test_accelerator