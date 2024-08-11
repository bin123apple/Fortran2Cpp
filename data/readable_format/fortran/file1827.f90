program TestSubroutines

    call TestGasMover()
    call TestGasUptake()
    call TestMacroChem()

    contains

    subroutine GasMover()
        ! Your original subroutine code
        return
    end subroutine GasMover

    subroutine GasUptake()
        ! Your original subroutine code
        return
    end subroutine GasUptake

    subroutine MacroChem()
        ! Your original subroutine code
        return
    end subroutine MacroChem

    subroutine TestGasMover()
        call GasMover
        print *, "GasMover called successfully."
        ! Add more specific tests and checks here as needed
    end subroutine TestGasMover

    subroutine TestGasUptake()
        call GasUptake
        print *, "GasUptake called successfully."
        ! Add more specific tests and checks here as needed
    end subroutine TestGasUptake

    subroutine TestMacroChem()
        call MacroChem
        print *, "MacroChem called successfully."
        ! Add more specific tests and checks here as needed
    end subroutine TestMacroChem

end program TestSubroutines