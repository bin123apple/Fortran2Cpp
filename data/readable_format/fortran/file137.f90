program test_asdf_data
  use asdf_data
  implicit none

  type(asdf_event) :: event
  integer :: i

  ! Allocate arrays within the event
  allocate(character(len=20) :: event%receiver_name_array(1))
  allocate(character(len=20) :: event%network_array(1))
  allocate(character(len=20) :: event%component_array(1))
  allocate(character(len=20) :: event%receiver_id_array(1))
  allocate(event%records(1)) ! Allocate space for one asdf_record
  allocate(event%records(1)%record(3)) ! Now allocate space for the record array within the asdf_record
  
  ! Set values
  event%event = 'TestEvent12345'
  event%nreceivers = 1
  event%receiver_name_array(1) = 'ReceiverOne'
  event%network_array(1) = 'NetworkOne'
  event%component_array(1) = 'ComponentOne'
  event%receiver_id_array(1) = 'ReceiverIDOne'
  event%records(1)%record = [1.0, 2.0, 3.0] ! Assign values to the record component array

  ! Print values to verify
  print *, 'Event Name:', trim(event%event)
  print *, 'Receiver Name:', trim(event%receiver_name_array(1))
  print *, 'Network Name:', trim(event%network_array(1))
  print *, 'Component Name:', trim(event%component_array(1))
  print *, 'Receiver ID:', trim(event%receiver_id_array(1))
  print *, 'Record Data:', (event%records(1)%record(i), i=1, size(event%records(1)%record))

end program test_asdf_data