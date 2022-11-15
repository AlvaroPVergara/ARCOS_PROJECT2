#include "histogram.hpp"
#include <fstream>

namespace images::common {


  void histogram::add_color(pixel p) noexcept {
    channels[red_channel][p.red()]++;
    channels[green_channel][p.green()]++;
    channels[blue_channel][p.blue()]++;
  }

  void histogram::write(std::ostream & os) const noexcept {
    for (const auto x: channels[red_channel]) {
      os << x << '\n';
    }
    for (const auto x: channels[green_channel]) {
      os << x << '\n';
    }
    for (const auto x: channels[blue_channel]) {
      os << x << '\n';
    }
  }

    void histogram::combinechannels(images::common::histogram& histo){

        for (int i = 0; i < num_levels; ++i){
            channels[red_channel][i] += histo.channels[red_channel][i];
            channels[green_channel][i] += histo.channels[green_channel][i];
            channels[blue_channel][i] += histo.channels[blue_channel][i];
        }
    }
}
