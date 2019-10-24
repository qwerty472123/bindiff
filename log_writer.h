#ifndef LOG_WRITER_H_
#define LOG_WRITER_H_

#include <string>

#include "third_party/zynamics/bindiff/writer.h"

namespace security::bindiff {

// Writes a human readable log file for debugging purposes.
class ResultsLogWriter : public Writer {
 public:
  explicit ResultsLogWriter(const std::string& filename);
  virtual void Write(const CallGraph& call_graph1, const CallGraph& call_graph2,
                     const FlowGraphs& flow_graphs1,
                     const FlowGraphs& flow_graphs2,
                     const FixedPoints& fixed_points);

 private:
  std::string filename_;
};

}  // namespace security::bindiff

#endif  // LOG_WRITER_H_
