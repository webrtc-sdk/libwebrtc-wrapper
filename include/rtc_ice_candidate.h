#ifndef LIB_WEBRTC_RTC_ICE_CANDIDATE_HXX
#define LIB_WEBRTC_RTC_ICE_CANDIDATE_HXX

#include "rtc_types.h"

namespace libwebrtc {

class RTCIceCandidate : public RefCountInterface {
 public:
  static LIB_WEBRTC_API scoped_refptr<RTCIceCandidate> Create(
      const string sdp, const string sdp_mid, int sdp_mline_index,
      SdpParseError* error);

 public:
  virtual const string candidate() const = 0;

  virtual const string sdp_mid() const = 0;

  virtual int sdp_mline_index() const = 0;

  virtual bool ToString(string& out) = 0;

 protected:
  virtual ~RTCIceCandidate() {}

 public:
  // The ICE username fragment (ufrag) of the ICE generation the candidate
  // belongs to. It changes with every ICE restart. Empty when unknown.
  // It is declared after the destructor so that the existing vtable slots
  // keep their positions.
  virtual const string username_fragment() const = 0;
};

}  // namespace libwebrtc

#endif  // LIB_WEBRTC_RTC_ICE_CANDIDATE_HXX
