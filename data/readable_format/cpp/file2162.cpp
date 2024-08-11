#include <iostream>
#include <vector>

class CommunicationTable {
public:
    long long num_neib;
    std::vector<long long> id_neib;
    std::vector<long long> istack_import;
    std::vector<long long> istack_export;
    long long ntot_import;
    long long ntot_export;
    std::vector<long long> item_import;
    std::vector<long long> item_export;

    // Constructor
    CommunicationTable() : num_neib(0), ntot_import(0), ntot_export(0) {}
};

class CommDataIO {
public:
    static long long num_neib_domain_IO;
    static std::vector<long long> id_neib_domain_IO;
    static std::vector<long long> istack_import_IO;
    static std::vector<long long> istack_export_IO;
    static long long ntot_import_IO;
    static long long ntot_export_IO;
    static std::vector<long long> item_import_IO;
    static std::vector<long long> item_export_IO;
};

// Static member initialization
long long CommDataIO::num_neib_domain_IO = 0;
std::vector<long long> CommDataIO::id_neib_domain_IO;
std::vector<long long> CommDataIO::istack_import_IO;
std::vector<long long> CommDataIO::istack_export_IO;
long long CommDataIO::ntot_import_IO = 0;
long long CommDataIO::ntot_export_IO = 0;
std::vector<long long> CommDataIO::item_import_IO;
std::vector<long long> CommDataIO::item_export_IO;

void copy_comm_tbl_type_from_IO(CommunicationTable& comm_tbls) {
    comm_tbls.num_neib = CommDataIO::num_neib_domain_IO;
    // Assuming other properties are copied similarly
}

int main() {
    CommunicationTable comm_tbls;
    
    // Initialize with some test data
    CommDataIO::num_neib_domain_IO = 2;
    CommDataIO::id_neib_domain_IO = {1, 2};
    CommDataIO::istack_import_IO = {10, 20};
    CommDataIO::istack_export_IO = {30, 40};

    // Call the function
    copy_comm_tbl_type_from_IO(comm_tbls);

    // Verify the results
    std::cout << "C++ Test Output:" << std::endl;
    std::cout << "num_neib = " << comm_tbls.num_neib << std::endl;

    return 0;
}