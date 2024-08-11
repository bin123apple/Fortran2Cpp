program personnel_management
  implicit none

  type :: person
    character(24) :: name = ""
    integer :: ss = 1
  end type person

  type, extends(person) :: education
    integer :: attainment = 0
    character(24) :: institution = ""
  end type education

  type, extends(education) :: service
    integer :: personnel_number = 0
    character(24) :: department = ""
  end type service
    
  type, extends(service) :: person_record
    type(person_record), pointer :: supervisor => null()
  end type person_record

  type(person_record), pointer :: recruit, supervisor

  ! Main program execution starts here
  ! Create a supervisor
  allocate(supervisor)
  supervisor%name = "Joe Honcho"
  supervisor%ss = 123455
  supervisor%attainment = 100
  supervisor%institution = "Celestial University"
  supervisor%personnel_number = 1
  supervisor%department = "Directorate"

  ! Create a recruit and assign a supervisor
  recruit => entry("John Smith", 123456, 1, "Bog Hill High School", 99, "Records", supervisor)

  ! Perform checks
  if (trim(recruit%name) /= "John Smith") stop 1
  if (recruit%name /= recruit%service%name) stop 2
  if (recruit%supervisor%ss /= 123455) stop 3
  if (recruit%supervisor%ss /= supervisor%person%ss) stop 4

  ! Deallocate pointers
  deallocate(supervisor)
  deallocate(recruit)

contains

  function entry(name, ss, attainment, institution, personnel_number, department, supervisor) result(new_person)
    integer :: ss, attainment, personnel_number
    character(len=*), intent(in) :: name, institution, department
    type(person_record), pointer, intent(in) :: supervisor
    type(person_record), pointer :: new_person

    allocate(new_person)
    new_person%person%name = name
    new_person%service%education%person%ss = ss
    new_person%service%attainment = attainment
    new_person%education%institution = institution
    new_person%personnel_number = personnel_number
    new_person%service%department = department
    new_person%supervisor => supervisor
  end function entry

end program personnel_management