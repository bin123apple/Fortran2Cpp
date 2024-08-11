module person_mod
  implicit none
  private
  public :: PERSON

  TYPE PERSON
    INTEGER :: AGE
    CHARACTER(LEN=50) :: NAME
  END TYPE PERSON
end module person_mod

program test_person
  use person_mod
  implicit none
  TYPE(PERSON) :: p

  ! Test Setup
  p = PERSON(21, 'JOHN SMITH')

  ! Test 1: Check Age
  if (p%AGE == 21) then
    print *, "Test 1 Passed: Age is correct."
  else
    print *, "Test 1 Failed: Age is incorrect."
  end if

  ! Test 2: Check Name
  if (trim(p%NAME) == 'JOHN SMITH') then
    print *, "Test 2 Passed: Name is correct."
  else
    print *, "Test 2 Failed: Name is incorrect."
  end if
end program test_person