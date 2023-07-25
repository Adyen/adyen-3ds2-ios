//
//  ADYProgressView.h
//  Adyen3DS2
//
//  Copyright © 2018 Adyen. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 A full screen progress view with a title, cancel button and loading indicator.
 */
@protocol ADYProgressView <NSObject>

/**
 Shows the progress view on the current top-most view.
 - Warning: This API is deprecated and should no longer be used. Use the `showWithCompletion:` method instead.
 */
- (void)show __attribute__((deprecated("Use showWithCompletion: instead. Will be removed in a future release.")));

/**
 Shows the progress view on the current top-most view, with a completion called when progress is shown on screen.
 */
- (void)showWithCompletion:(void (^)(void))completion;

/**
 Hides the progress view.
 - Warning: This API is deprecated and should no longer be used. Use the `hideWithCompletion:` method instead.
 */
- (void)hide __attribute__((deprecated("Use hideWithCompletion: instead. Will be removed in a future release.")));

/**
 Hides the progress view, with a completion block called when progress is hidden.
 */
- (void)hideWithCompletion:(void (^)(void))completion;

@end

NS_ASSUME_NONNULL_END
