#ifndef MUXSDKPlayerBinding_h
#define MUXSDKPlayerBinding_h

#import <Foundation/Foundation.h>

#if __has_feature(modules)
@import AVKit;
@import AVFoundation;
#else
#import <AVKit/AVKit.h>;
#import <AVFoundation/AVFoundation.h>;
#endif


typedef NS_ENUM(NSUInteger, MUXSDKPlayerState) {
    MUXSDKPlayerStateReady,
    MUXSDKPlayerStateViewInit,
    MUXSDKPlayerStatePlay,
    MUXSDKPlayerStateBuffering,
    MUXSDKPlayerStatePlaying,
    MUXSDKPlayerStatePaused,
    MUXSDKPlayerStateError,
    MUXSDKPlayerStateViewEnd,
};


@interface MUXSDKPlayerBinding : NSObject {
@private
    NSString *_name;
    NSString *_software;
    AVPlayer *_player;
    AVPlayerItem *_playerItem;
    id _timeObserver;
    MUXSDKPlayerState _state;
    CGSize _videoSize;
    CMTime _videoDuration;
    BOOL _videoIsLive;
    NSString *_videoURL;
    CFAbsoluteTime _lastTimeUpdate;
    NSTimer *_timeUpdateTimer;
    CFAbsoluteTime _lastPlayheadTimeUpdated;
    float _lastPlayheadTimeMs;
    BOOL _seeking;
    BOOL _started;
    NSUInteger _lastMediaRequest;
    NSUInteger _lastMediaRequestBytes;
    NSUInteger _lastErrorLogEventCount;
    NSUInteger _lastTransferEventCount;
    double _lastTransferDuration;
    long long _lastTransferredBytes;
}

- (id)initWithName:(NSString *)name andSoftware:(NSString *)software;
- (void)attachAVPlayer:(AVPlayer *)player;
- (void)detachAVPlayer;
- (CGRect)getViewBounds;
- (void)dispatchViewInit;
- (void)dispatchPlayerReady;
- (void)dispatchPlay;
- (void)dispatchPlaying;
- (void)dispatchPause;
- (void)dispatchTimeUpdateEvent:(CMTime)time;
- (void)dispatchError;
- (void)dispatchViewEnd;

@end


@interface MUXSDKAVPlayerViewControllerBinding : MUXSDKPlayerBinding {
@private
    AVPlayerViewController *_viewController;
}

- (id)initWithName:(NSString *)name software:(NSString *)software andView:(AVPlayerViewController *)view;

@end


@interface MUXSDKAVPlayerLayerBinding : MUXSDKPlayerBinding {
@private
    AVPlayerLayer *_view;
}

- (id)initWithName:(NSString *)name software:(NSString *)software andView:(AVPlayerLayer *)view;

@end


#endif
