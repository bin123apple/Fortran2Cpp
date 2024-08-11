program ESSAI
    implicit none
    call Pas_1
contains

    subroutine Pas_1
        implicit none
        real(kind=8) :: oper0
        real(kind=8) :: oper1
        real(kind=8) :: resul

        oper0 = 3.0d0
        oper1 = 4.0d0

        print *, '--- Avant --- oper0:', oper0, 'oper1:', oper1, 'resul:', resul

        call Mouv(oper0, oper1, resul)

        print *, '--- Apres --- oper0:', oper0, 'oper1:', oper1, 'resul:', resul
    end subroutine Pas_1

    subroutine Mouv(oper0, oper1, resul)
        implicit none
        real(kind=8), intent(inout) :: oper0
        real(kind=8), intent(in) :: oper1
        real(kind=8), intent(out) :: resul

        resul = oper0 + oper1
        oper0 = 8.0d0
    end subroutine Mouv

end program ESSAI