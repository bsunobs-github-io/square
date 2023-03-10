/// \file
/// \ingroup tutorial_ntuple
/// \notebook
/// Example of converting data stored in a TTree into an RNTuple
///
/// \macro_image
/// \macro_code
///
/// \date December 2022
/// \author The ROOT Team

// NOTE: The RNTuple classes are experimental at this point.
// Functionality, interface, and data format is still subject to changes.
// Do not use for real data!

// Until C++ runtime modules are universally used, we explicitly load the ntuple library.  Otherwise
// triggering autoloading from the use of templated types would require an exhaustive enumeration
// of "all" template instances in the LinkDef file.
R__LOAD_LIBRARY(ROOTNTupleUtil)

#include <ROOT/RNTuple.hxx>
#include <ROOT/RNTupleImporter.hxx>

#include <TFile.h>
#include <TROOT.h>

// Import classes from experimental namespace for the time being
using RNTuple = ROOT::Experimental::RNTuple;
using RNTupleImporter = ROOT::Experimental::RNTupleImporter;
using RNTupleReader = ROOT::Experimental::RNTupleReader;

// Input and output
constexpr char const *kTreeFileName = "http://root.cern.ch/files/HiggsTauTauReduced/GluGluToHToTauTau.root";
constexpr char const *kTreeName = "Events";
constexpr char const *kNTupleFileName = "ntpl008_import.root";

void ntpl008_import()
{
   // Use multiple threads to compress RNTuple data
   ROOT::EnableImplicitMT();

   // RNTupleImporter::Create() returns a wrapper for an RNTupleImporter. If the creation fails,
   // the result will contain an exception. Calling Unwrap() returns the actual RNTupleImporter
   // class or throws the exception in case of errors.
   auto importer = RNTupleImporter::Create(kTreeFileName, kTreeName, kNTupleFileName).Unwrap();

   // Using `ThrowOnError()` makes sure that the macro abort if the import fails.
   importer->Import().ThrowOnError();

   // Inspect the schema of the written RNTuple
   auto file = std::unique_ptr<TFile>(TFile::Open(kNTupleFileName));
   if (!file || file->IsZombie()) {
      std::cerr << "cannot open " << kNTupleFileName << std::endl;
      return;
   }
   auto ntpl = file->Get<RNTuple>("Events");
   auto reader = RNTupleReader::Open(ntpl);
   reader->PrintInfo();
}
