//
//  ADYService.h
//  Adyen3DS2
//
//  Copyright © 2018 Adyen. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Adyen3DS2/ADYServiceParameters.h>
#import <Adyen3DS2/ADYAppearanceConfiguration.h>
#import <Adyen3DS2/ADYTransaction.h>
#import <Adyen3DS2/ADYWarning.h>

NS_ASSUME_NONNULL_BEGIN

/**
 The current 3DS2 SDK version of the SDK.
 */
extern NSString *ADY3DS2SDKVersion(void);

/**
 Provides a starting point for 3D-Secure 2.0 authentication. Used for initialization of the service and the creation of a transaction.
 
 @note This class corresponds to the `Three3DS2Service` interface in the specification.
 */
@interface ADYService : NSObject

/**
 The current version of the SDK.
 */
@property (class, nonatomic, copy, readonly) NSString *version;

/**
 Array containing the warnings that were produced during initialization of the service.
 */
@property (nonatomic, copy, readonly) NSArray<ADYWarning *> *warnings;

/**
 Asynchronously creates a service and prepares it for creating a transaction.

 @param parameters A collection of parameters to use during initialization of the service.
 @param appearanceConfiguration The configuration of the appearance of the challenge flow. When `nil`, a default appearance configuration is used.
 @param completionHandler The completion handler to invoke when the service has been initialized.
 */
+ (void)serviceWithParameters:(ADYServiceParameters *)parameters
      appearanceConfiguration:(nullable ADYAppearanceConfiguration *)appearanceConfiguration
            completionHandler:(void (^)(ADYService *service))completionHandler;

/**
 Creates a new transaction.
 
 @param messageVersion The version of the protocol to be used during the transaction.
 @param error A pointer to an error object that is set to an @p NSError instance when an error occurs.
 @return An initialized transaction, or @p nil if a transaction could not be initialized.
 */
- (nullable ADYTransaction *)transactionWithMessageVersion:(NSString *)messageVersion error:(NSError *__nullable *__nullable)error;

@end

NS_ASSUME_NONNULL_END
