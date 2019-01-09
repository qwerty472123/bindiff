#ifndef IDA_UI_H_
#define IDA_UI_H_

#include "third_party/absl/strings/string_view.h"
#include "third_party/zynamics/binexport/types.h"
#include "util/task/status.h"

namespace security {
namespace bindiff {

constexpr double kManualMatch = -1.0;

// Returns a 32-bit RGB color value suitable for colorizing match similarities.
// If passed kManualMatch, returns a color that can be used to mark manual
// matches.
uint32_t GetMatchColor(double value);

// Copies a short unformatted plain text string to clipboard. Short in this
// context means no more than a few kilobytes. There is no hard limit, but due
// to escaping there might be some memory blow-up.
util::Status CopyToClipboard(absl::string_view data);

}  // namespace bindiff
}  // namespace security

#endif  // IDA_UI_H_
