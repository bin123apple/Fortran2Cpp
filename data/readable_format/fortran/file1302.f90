program test_namecheck
  implicit none

  ! Enumerated type for XML versions
  integer, parameter :: XML1_0 = 1, XML1_1 = 2

  ! Type definition for xml_doc_state
  type xml_doc_state
     integer :: xml_version = XML1_0
  end type xml_doc_state

  type(xml_doc_state) :: xds
  logical :: result

  ! Initial XML version (default is XML1_0)
  result = checkQName('abcd', xds)
  print *, result
  result = checkQName('1abcd', xds)
  print *, result
  result = checkQName(':abcd', xds)
  print *, result
  result = checkQName('#abcd', xds)
  print *, result
  result = checkQName('e:abcd', xds)
  print *, result

  ! Change XML version to XML1_1
  xds%xml_version = XML1_1

  result = checkQName('abcd', xds)
  print *, result
  result = checkQName('1abcd', xds)
  print *, result
  result = checkQName(':abcd', xds)
  print *, result
  result = checkQName('#abcd', xds)
  print *, result
  result = checkQName('e:abcd', xds)
  print *, result

contains

  ! Function to check QName validity
  function checkQName(name, xds) result(isValid)
    character(len=*), intent(in) :: name
    type(xml_doc_state), intent(in) :: xds
    logical :: isValid

    isValid = .true.

    ! Implement QName check logic here
    ! Placeholder logic for demonstration
    if (len(trim(name)) == 0 .or. name(1:1) == '1' .or. name(1:1) == ':' .or. name(1:1) == '#') then
       isValid = .false.
    else if (index(name, ':') /= 0 .and. xds%xml_version == XML1_0) then
       isValid = .false.
    endif
  end function checkQName

end program test_namecheck