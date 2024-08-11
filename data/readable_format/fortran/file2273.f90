program test_constants
  implicit none
  integer :: ntq, ntc, nss, nt, ng0, ng, nl
  integer :: ngd0, ngd, ntqss, norbit, Ngrid

  parameter (ntq=200, ntc=0, nss=1)
  parameter (nt=ntq+nss*ntc)
  parameter (ng0=100, ng=ntq*ng0, nl=13)
  parameter (ngd0=500, ngd=ntq*ngd0)
  parameter (ntqss=ntq+nss)
  parameter (norbit=800, Ngrid=0)

  call check_constants()

contains

  subroutine check_constants()
    if (ntq /= 200) call report_error('ntq')
    if (ntc /= 0) call report_error('ntc')
    if (nss /= 1) call report_error('nss')
    if (nt /= 200) call report_error('nt')
    if (ng0 /= 100) call report_error('ng0')
    if (ng /= 20000) call report_error('ng')
    if (nl /= 13) call report_error('nl')
    if (ngd0 /= 500) call report_error('ngd0')
    if (ngd /= 100000) call report_error('ngd')
    if (ntqss /= 201) call report_error('ntqss')
    if (norbit /= 800) call report_error('norbit')
    if (Ngrid /= 0) call report_error('Ngrid')
    print *, 'All constants are correct.'
  end subroutine check_constants

  subroutine report_error(name)
    character(len=*) :: name
    print *, 'Error: constant ', name, ' is incorrect.'
    stop
  end subroutine report_error

end program test_constants