module greatRSDMod
    implicit none
contains
    subroutine great_rsd(a, b)
        integer, intent(in) :: a, b
        print *, "Called great_rsd with", a, "and", b, ". Sum is:", a + b
    end subroutine great_rsd
end module greatRSDMod

program testGreatRSD
    use greatRSDMod
    implicit none
    call great_rsd(1, 2)
    call great_rsd(3, 4)
    call great_rsd(-5, -6)
    call great_rsd(0, 0)
end program testGreatRSD