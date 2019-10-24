#include "third_party/zynamics/bindiff/ida/statistics_chooser.h"

#include <cstring>
#include <vector>

#include "third_party/zynamics/bindiff/ida/main_plugin.h"

namespace security::bindiff {

constexpr const int StatisticsChooser::kColumnWidths[];
constexpr const char* const StatisticsChooser::kColumnNames[];
constexpr const char StatisticsChooser::kTitle[];

const void* StatisticsChooser::get_obj_id(size_t* len) const {
  *len = strlen(kTitle);
  return kTitle;
}

size_t StatisticsChooser::get_count() const {
  return Plugin::instance()->results()->GetNumStatistics();
}

void StatisticsChooser::get_row(qstrvec_t* cols, int* /* icon_ */,
                                chooser_item_attrs_t* /* attrs */,
                                size_t n) const {
  auto statistic = Plugin::instance()->results()->GetStatisticDescription(n);
  (*cols)[0] = statistic.name.c_str();
  (*cols)[1] = (statistic.is_count ? std::to_string(statistic.count)
                                   : std::to_string(statistic.value))
                   .c_str();
}

}  // namespace security::bindiff
