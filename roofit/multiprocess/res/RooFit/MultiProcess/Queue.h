/*
 * Project: RooFit
 * Authors:
 *   PB, Patrick Bos, Netherlands eScience Center, p.bos@esciencecenter.nl
 *   IP, Inti Pelupessy, Netherlands eScience Center, i.pelupessy@esciencecenter.nl
 *
 * Copyright (c) 2021, CERN
 *
 * Redistribution and use in source and binary forms,
 * with or without modification, are permitted according to the terms
 * listed in LICENSE (http://roofit.sourceforge.net/license.txt)
 */
#ifndef ROOT_ROOFIT_MultiProcess_Queue
#define ROOT_ROOFIT_MultiProcess_Queue

#include "RooFit/MultiProcess/types.h"
#include "RooFit/MultiProcess/Messenger.h"

namespace RooFit {
namespace MultiProcess {

class Queue {
public:
   virtual ~Queue() = default;

   /// Have a worker ask for a task-message from the queue
   ///
   /// \param[out] job_task JobTask reference to put the Job ID and the task index into.
   /// \return true if a task was popped from the queue successfully, false if the queue was empty.
   virtual bool pop(JobTask &job_task) = 0;

   /// Enqueue a task
   ///
   /// \param[in] job_task JobTask object that contains the Job ID and the task index.
   virtual void add(JobTask job_task) = 0;

   void loop();

   void process_master_message(M2Q message);
   void process_worker_message(std::size_t this_worker_id, W2Q message);

protected:
   std::size_t N_tasks_ = 0; // total number of received tasks
   std::size_t N_tasks_at_workers_ = 0;
};

} // namespace MultiProcess
} // namespace RooFit

#endif // ROOT_ROOFIT_MultiProcess_Queue
