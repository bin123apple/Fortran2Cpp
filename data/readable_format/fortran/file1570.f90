module counters
  implicit none
  save

  integer :: killed_photons_geo = 0
  integer :: killed_photons_int = 0
  integer :: killed_photons_reabs = 0
end module counters

program test_counters
    use counters
    implicit none

    ! Test incrementing killed_photons_geo
    killed_photons_geo = killed_photons_geo + 1
    if (killed_photons_geo /= 1) then
        print *, "Test failed for killed_photons_geo"
    else
        print *, "Test passed for killed_photons_geo"
    endif

    ! Test incrementing killed_photons_int
    killed_photons_int = killed_photons_int + 1
    if (killed_photons_int /= 1) then
        print *, "Test failed for killed_photons_int"
    else
        print *, "Test passed for killed_photons_int"
    endif
    
    ! Test incrementing killed_photons_reabs
    killed_photons_reabs = killed_photons_reabs + 1
    if (killed_photons_reabs /= 1) then
        print *, "Test failed for killed_photons_reabs"
    else
        print *, "Test passed for killed_photons_reabs"
    endif
end program test_counters