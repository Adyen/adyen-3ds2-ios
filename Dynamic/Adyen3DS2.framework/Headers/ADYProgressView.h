//
//  ADYProgressView.h
//  Adyen3DS2
//
//  Copyright © 2018 Adyen. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 An overlay with a loading indicator, indicating an indefinite activity.
 */
@interface ADYProgressView : UIView

/**
 The title displayed in the progress view. Defaults to "Processing…".
 */
@property (nonatomic, copy, readwrite) NSString *title;

/**
 Shows the progress view on the current top-most view.
 */
- (void)show;

/**
 Hides the progress view.
 */
- (void)hide;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;
- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
