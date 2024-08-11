program test_correctflux
  implicit none
  integer, parameter :: nef=2, nfa=1, nfb=2
  integer :: ipnei(3) = [1, 2, 3]
  integer :: neifa(2) = [1, 2]
  integer :: neiel(2) = [2, 0]
  integer :: ielfa(4,2) = reshape([1, -1, 2, -2], [4, 2], (/2, 2/))
  integer :: ifabou(4) = [0, 0, 0, 1]
  real(8) :: flux(2) = [0.0d0, 0.0d0]
  real(8) :: vfa(0:7,2) = reshape([0d0, 0d0, 0d0, 0d0, 0.5d0, 0d0, 0d0, 0d0, &
                                   0d0, 0d0, 0d0, 0d0, 0.6d0, 0d0, 0d0, 0d0], [8, 2])
  real(8) :: advfa(2) = [1.0d0, 1.5d0]
  real(8) :: area(2) = [1.0d0, 1.0d0]
  real(8) :: vel(2,0:7) = reshape([0d0, 0d0, 0d0, 0.4d0, 0d0, 0d0, 0d0, 0d0, &
                                   0d0, 0d0, 0d0, 0.3d0, 0d0, 0d0, 0d0, 0d0], [2, 8])
  real(8) :: alet(2) = [0.2d0, 0.3d0]
  real(8) :: ale(2) = [0.2d0, 0.3d0]
  real(8) :: xxnj(3,2) = reshape([1d0, 0d0, 0d0, 1d0, 0d0, 0d0], [3, 2])
  real(8) :: gradpcfa(3,2) = reshape([0.1d0, 0.2d0, 0.3d0, 0.1d0, 0.2d0, 0.3d0], [3, 2])
  
  call correctflux(nef,ipnei,neifa,neiel,flux,vfa,advfa,area,vel,alet,ielfa,ale,ifabou,nfa,nfb,xxnj,gradpcfa)
  
  print *, 'Flux results:', flux
end program test_correctflux

subroutine correctflux(nef,ipnei,neifa,neiel,flux,vfa,advfa,area,vel,alet,ielfa,ale,ifabou,nefa,nefb,xxnj,gradpcfa)
  implicit none
  integer :: i,nef,indexf,ipnei(*),neifa(*),neiel(*),ielfa(4,*),iel,ifa,ifabou(*),indexb,nefa,nefb
  real(8) :: flux(*),vfa(0:7,*),advfa(*),area(*),vel(nef,0:7),alet(*),ale(*),xxnj(3,*),gradpcfa(3,*)

  do i=nefa,nefb
    do indexf=ipnei(i)+1,ipnei(i+1)
      ifa=neifa(indexf)
      iel=neiel(indexf)
      if(iel.gt.0) then
        flux(indexf)=flux(indexf)+vfa(5,ifa)*advfa(ifa)* &
        ((vel(i,4)-vel(iel,4))*alet(indexf)-(gradpcfa(1,ifa)*xxnj(1,indexf) &
        +gradpcfa(2,ifa)*xxnj(2,indexf)+gradpcfa(3,ifa)*xxnj(3,indexf)))
      else
        indexb=-ielfa(2,ifa)
        if(indexb.gt.0) then
          if(((ifabou(indexb+1).eq.0).or.(ifabou(indexb+2).eq.0).or.(ifabou(indexb+3).eq.0)).and. &
          (ifabou(indexb+4).ne.0)) then
            flux(indexf)=flux(indexf)+vfa(5,ifa)*advfa(ifa)*(vel(i,4)*ale(indexf) &
            -(gradpcfa(1,ifa)*xxnj(1,indexf)+gradpcfa(2,ifa)*xxnj(2,indexf) &
            +gradpcfa(3,ifa)*xxnj(3,indexf)))
          end if
        end if
      end if
    end do
  end do
end subroutine correctflux