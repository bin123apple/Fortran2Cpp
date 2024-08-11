module isochrones
    implicit none
    integer, parameter :: niso = 9
    character(len=80), dimension(niso) :: isofile
    data isofile /"isochrones/UBVRIJHKsKp/fehm25afep0.UBVRIJHKsKp", &
                  "isochrones/UBVRIJHKsKp/fehm20afep0.UBVRIJHKsKp", &
                  "isochrones/UBVRIJHKsKp/fehm15afep0.UBVRIJHKsKp", &
                  "isochrones/UBVRIJHKsKp/fehm10afep0.UBVRIJHKsKp", &
                  "isochrones/UBVRIJHKsKp/fehm05afep0.UBVRIJHKsKp", &
                  "isochrones/UBVRIJHKsKp/fehp00afep0.UBVRIJHKsKp", &
                  "isochrones/UBVRIJHKsKp/fehp02afep0.UBVRIJHKsKp", &
                  "isochrones/UBVRIJHKsKp/fehp03afep0.UBVRIJHKsKp", &
                  "isochrones/UBVRIJHKsKp/fehp05afep0.UBVRIJHKsKp" /
end module isochrones

program test_isochrones
    use isochrones
    implicit none
    integer :: i
    logical :: all_tests_passed

    all_tests_passed = .true.

    do i = 1, niso
        if (trim(isofile(i)) /= trim(expected_path(i))) then
            print *, "Test failed for isofile(", i, ")"
            all_tests_passed = .false.
        end if
    end do

    if (all_tests_passed) then
        print *, "All tests passed."
    else
        print *, "Some tests failed."
    end if

contains

    function expected_path(i) result(path)
        integer, intent(in) :: i
        character(len=80) :: path

        select case(i)
            case(1)
                path = "isochrones/UBVRIJHKsKp/fehm25afep0.UBVRIJHKsKp"
            case(2)
                path = "isochrones/UBVRIJHKsKp/fehm20afep0.UBVRIJHKsKp"
            case(3)
                path = "isochrones/UBVRIJHKsKp/fehm15afep0.UBVRIJHKsKp"
            case(4)
                path = "isochrones/UBVRIJHKsKp/fehm10afep0.UBVRIJHKsKp"
            case(5)
                path = "isochrones/UBVRIJHKsKp/fehm05afep0.UBVRIJHKsKp"
            case(6)
                path = "isochrones/UBVRIJHKsKp/fehp00afep0.UBVRIJHKsKp"
            case(7)
                path = "isochrones/UBVRIJHKsKp/fehp02afep0.UBVRIJHKsKp"
            case(8)
                path = "isochrones/UBVRIJHKsKp/fehp03afep0.UBVRIJHKsKp"
            case(9)
                path = "isochrones/UBVRIJHKsKp/fehp05afep0.UBVRIJHKsKp"
            case default
                path = "unknown"
        end select
    end function expected_path
end program test_isochrones