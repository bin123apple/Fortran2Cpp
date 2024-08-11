program generate_sph_grids

  implicit none

  ! Mock initialization of MPI
  call calypso_MPI_init
  ! Mock initialization of generating spherical grids
  call init_gen_sph_grids
  ! Mock analysis of generated spherical grids
  call analyze_gen_sph_grids
  ! Mock finalization of MPI
  call calypso_MPI_finalize

  write(*,*) '***** program finished *****'
  stop

contains

  subroutine calypso_MPI_init
    print *, "MPI Initialized"
  end subroutine calypso_MPI_init

  subroutine init_gen_sph_grids
    print *, "Generating Spherical Grids Initialized"
  end subroutine init_gen_sph_grids

  subroutine analyze_gen_sph_grids
    print *, "Analysis of Generated Spherical Grids Done"
  end subroutine analyze_gen_sph_grids

  subroutine calypso_MPI_finalize
    print *, "MPI Finalized"
  end subroutine calypso_MPI_finalize

end program generate_sph_grids