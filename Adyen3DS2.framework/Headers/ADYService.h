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
 Provides a starting point for 3D-Secure 2.0 authentication. Used for initialization of the service and the creation of a transaction.
 
 @note This class corresponds to the `Three3DS2Service` interface in the specification.
 */
@interface ADYService : NSObject

/**
 The current version of the SDK.
 */
@property (class, nonatomic, copy, readonly) NSString *version;

/**
 Array containing the warnings that were produced while conducting security checks during initialization of the service.
 
 @note Will be @p nil until the service is initialized.
 */
@property (nonatomic, copy, readonly, nullable) NSArray<ADYWarning *> *warnings;

/**
 Creates a new service.

 @param parameters A collection of arbitrary parameters used during initialization of the service.
 @param appearanceConfiguration The configuration of the appearance of the challenge flow. When `nil`, a default appearance configuration is used.
 @param completionHandler The completion handler to invoke when the service is created.
 */
+ (void)serviceWithParameters:(nullable ADYServiceParameters *)parameters appearanceConfiguration:(nullable ADYAppearanceConfiguration *)appearanceConfiguration completionHandler:(void (^)(ADYService *))completionHandler;

/**
 Creates a new transaction.

 @param directoryServerIdentifier The identifier of the directory server for which to create the transaction. When `nil`, the directory server information is assumed to have been passed in the parameters during initialization of the service.
 @param messageVersion The version of the protocol to be used during the transaction, or `nil` to use the latest supported version.
 @param error A pointer to an error object that is set to an @p NSError instance when an error occurs.
 @return An initialized transaction, or @p nil if a transaction could not be initialized.
 */
- (nullable ADYTransaction *)transactionWithDirectoryServerIdentifier:(nullable NSString *)directoryServerIdentifier messageVersion:(nullable NSString *)messageVersion error:(NSError *__nullable *__nullable)error;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
