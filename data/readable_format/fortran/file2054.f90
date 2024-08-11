program test_openacc
  use openacc
  implicit none

  integer :: num_devices
  integer :: selected_device

  ! Initialize OpenACC
  call acc_init(acc_device_nvidia)

  ! Test 1: Check available NVIDIA devices
  num_devices = acc_get_num_devices(acc_device_nvidia)
  if (num_devices >= 1) then
    print *, "Test 1 Passed: At least one NVIDIA GPU available."
  else
    print *, "Test 1 Failed: No NVIDIA GPUs available."
    stop
  endif

  ! Test 2: Set device and check
  selected_device = 0
  call acc_set_device_num(selected_device, acc_device_nvidia)
  if (acc_get_device_num(acc_device_nvidia) == selected_device) then
    print *, "Test 2 Passed: GPU device 0 selected successfully."
  else
    print *, "Test 2 Failed: Incorrect GPU device selected."
    stop
  endif

  ! Shutdown OpenACC
  call acc_shutdown(acc_device_nvidia)
end program test_openacc