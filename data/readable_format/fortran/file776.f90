MODULE ppm_module_data_state
    INTEGER :: ppm_map_type_state = 0
    INTEGER :: ppm_nrecvlist_state = 0
    INTEGER :: ppm_nsendlist_state = 0
    INTEGER :: ppm_nsendbuffer_state = 0
    INTEGER :: ppm_buffer_set_state = 0

    INTEGER, DIMENSION(:), ALLOCATABLE :: ppm_psendbuffer_state
    INTEGER, DIMENSION(:), ALLOCATABLE :: ppm_buffer2part_state

    INTEGER, DIMENSION(:), ALLOCATABLE :: ppm_irecvlist_state
    INTEGER, DIMENSION(:), ALLOCATABLE :: ppm_isendlist_state
END MODULE ppm_module_data_state

PROGRAM test_ppm_module_data_state
    USE ppm_module_data_state
    IMPLICIT NONE

    PRINT *, 'Testing initialization...'
    PRINT *, ppm_map_type_state, ppm_nrecvlist_state, ppm_nsendlist_state, ppm_nsendbuffer_state, ppm_buffer_set_state

    ALLOCATE(ppm_psendbuffer_state(10))
    ppm_psendbuffer_state = 5
    PRINT *, 'Testing dynamic arrays...'
    PRINT *, ppm_psendbuffer_state

    DEALLOCATE(ppm_psendbuffer_state)
    IF (ALLOCATED(ppm_buffer2part_state)) DEALLOCATE(ppm_buffer2part_state)
    IF (ALLOCATED(ppm_irecvlist_state)) DEALLOCATE(ppm_irecvlist_state)
    IF (ALLOCATED(ppm_isendlist_state)) DEALLOCATE(ppm_isendlist_state)
END PROGRAM test_ppm_module_data_state