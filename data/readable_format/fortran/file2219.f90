program wb_dma_transfer_test
  implicit none
  logical :: test_passed

  ! Call the functions to set type overrides
  call uvm_set_type_override("wb_dma_transfer_seq", "wb_dma_infact_single_transfer_seq")
  call uvm_set_type_override("wb_dma_config_seq", "wb_dma_infact_fields_config_seq")

  ! Check overrides (this is a mock check, replace with actual check if possible)
  test_passed = check_override("wb_dma_transfer_seq", "wb_dma_infact_single_transfer_seq") .and. &
                check_override("wb_dma_config_seq", "wb_dma_infact_fields_config_seq")

  if (test_passed) then
    print *, "Test Passed"
  else
    print *, "Test Failed"
  end if

contains

  subroutine uvm_set_type_override(original_type, new_type)
    character(len=*), intent(in) :: original_type, new_type
    ! Placeholder for the actual code that sets the type override
    print *, "Overriding ", original_type, " with ", new_type
  end subroutine uvm_set_type_override

  logical function check_override(original_type, expected_new_type)
    character(len=*), intent(in) :: original_type, expected_new_type
    ! Placeholder for checking if the override was successful
    check_override = .true.  ! Assume it returns true for this mock-up
  end function check_override

end program wb_dma_transfer_test