program welcome_program
    call welcome
contains
    subroutine welcome
        implicit none
        print *, '              Welcome to FIREBALL QMD !        '
        print *, '          A fast local orbital QMD Package     '
        print *, '     brought to you by the Fireball Committee: '
        print *, '  '
        print *, '                 James P. Lewis '
        print *, '        Department of Physics and Astronomy '
        print *, '             Brigham Young University '
        print *, '  '
        print *, '                 Otto F. Sankey '
        print *, '       Department of Physics and Astronomy '
        print *, '           Arizona State University '
        print *, '  '
        print *, '                  Jose Ortega '
        print *, '             Departmento de Fisica '
        print *, '       Teorica de la Materia Condensada '
        print *, '        Universidad Autonoma de Madrid '
        print *, '  '
        print *, '                Pavel Jelinek '
        print *, '             Institute of Physics '
        print *, '            Prague, Czech Republic '
        print *, '  '
        print *, '  '
        print *, '             with contributions from: '
        print *, '  '
        print *, ' Alex A. Demkov (Motorola Physical Sciences Research Labs)'
        print *, ' Gary B. Adams (Arizona State University) '
        print *, ' Jian Jun Dong (Arizona State University) '
        print *, ' David A. Drabold (Ohio University) '
        print *, ' Peter A. Fedders (Washington University) '
        print *, ' Kurt R. Glaesemann (University of Utah) '
        print *, ' Kevin Schmidt (Arizona State University) '
        print *, ' Spencer Shellman (University of Utah) '
        print *, ' John Tomfohr (Arizona State University) '
        print *, ' Hao Wang (Brigham Young University) '
        print *, ' Daniel G. Trabada (Universidad Autonoma de Madrid) '
        print *, ' Jesus I. Mendieta-Moreno (Universidad Autonoma de Madrid) '
        print *, '  '
        print *, '  '
        print *, '  fireball-qmd is a free (GPLv3) open project  '
        print *, '  '
        print *, '  '
    end subroutine welcome
end program welcome_program