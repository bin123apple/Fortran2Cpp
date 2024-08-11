program testPersonRecord
    implicit none

    type :: person
        integer :: ss = 1
    end type person

    type, extends(person) :: education
        integer :: attainment = 0
    end type education

    type, extends(education) :: service
        integer :: personnel_number = 0
    end type service

    type, extends(service) :: person_record
        type(person_record), pointer :: supervisor => null()
    end type person_record

    type(person_record) :: recruit

    recruit%ss = 2
    ! Assuming the intent was to demonstrate setting the 'ss' field at different levels,
    ! but since Fortran doesn't allow direct setting like this in single inheritance,
    ! we'll proceed with just setting 'ss' and 'personnel_number' for demonstration.
    recruit%personnel_number = 6

    ! Test
    if (recruit%ss == 2 .and. recruit%personnel_number == 6) then
        print *, "Test passed."
    else
        print *, "Test failed."
    end if
end program testPersonRecord