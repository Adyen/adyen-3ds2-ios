//
//  ADYServiceParameters.h
//  Adyen3DS2
//
//  Copyright © 2018 Adyen. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 A collection of arbitrary parameters used during the initialization of the ADYService class.
 
 @note This class corresponds to the `ConfigParameters` class in the specification.
 */
@interface ADYServiceParameters : NSObject

/**
 The identifier of the directory server to use during the transaction creation phase.
 */
@property (nonatomic, copy, readwrite, nullable) NSString *directoryServerIdentifier __attribute__((deprecated("Use initWithDirectoryServerIdentifier:directoryServerPublicKey:directoryServerRootCertificates instead. Will be removed in a future release.")));

/**
 The public key of the directory server to use during the transaction creation phase.
 
 The value of this property should be a base64-encoded JSON Web Key.
 */
@property (nonatomic, copy, readwrite, nullable) NSString *directoryServerPublicKey __attribute__((deprecated("Use initWithDirectoryServerIdentifier:directoryServerPublicKey:directoryServerRootCertificates instead. Will be removed in a future release.")));

/**
 The root certificates of the directory server to use during the transaction creation phase.
 
 The value of this property should be a JSON Web Signature compact serialization.
 */
@property (nonatomic, copy, readwrite, nullable) NSString *directoryServerRootCertificates __attribute__((deprecated("Use initWithDirectoryServerIdentifier:directoryServerPublicKey:directoryServerRootCertificates instead. Will be removed in a future release.")));

/**
 Returns the value associated with a given key in the default group.

 @param key The key for which to return the corresponding value.
 @return The value associated with @p key, or @p nil if no value was set.
 */
- (nullable NSString *)valueForKey:(NSString *)key;

/**
 Returns the value associated with a given key in a specific group.

 @param key The key for which to return the corresponding value.
 @param group The group from which the value should be retrieved, or @p nil if the default group should be used.
 @return The value associated with @p key, or @p nil if no value was set.
 */
- (nullable NSString *)valueForKey:(NSString *)key inGroup:(nullable NSString *)group;


/**
 Sets the value for a given key in the default group.

 @param value The value to set, or @p nil to remove the value.
 @param key The key for @p value.
 */
- (void)setValue:(nullable NSString *)value forKey:(NSString *)key;

/**
 Sets the value for a given key in a specific group.

 @param value The value to set, or @p nil to remove the value.
 @param key The key for @p value.
 @param group The group in which to set the value, or @p nil if the default group should be used.
 */
- (void)setValue:(nullable NSString *)value forKey:(NSString *)key inGroup:(nullable NSString *)group;

/**
 Removes the given key and its associated value from the default group.

 @param key The key to remove along with its associated value.
 */
- (void)removeValueForKey:(NSString *)key;

/**
 Removes the given key and its associated value from a specific group.

 @param key The key to remove along with its associated value.
 @param group The group from which to remove the key and its associated value, or @p if the default group should be used.
 */
- (void)removeValueForKey:(NSString *)key inGroup:(nullable NSString *)group;


/**
 A deprecated way to initialize `ADYServiceParameters`. Use `initWithDirectoryServerIdentifier:directoryServerPublicKey:directoryServerRootCertificates` instead.
 */
- (instancetype)init __attribute__((deprecated("Use initWithDirectoryServerIdentifier:directoryServerPublicKey:directoryServerRootCertificates instead. Will be removed in a future release.")));

/**
 Creates and returns an instance of `ADYServiceParameters`.

 @param directoryServerIdentifier The identifier of the directory server to use during the transaction creation phase.
 @param directoryServerPublicKey The public key of the directory server to use during the transaction creation phase. The value of this property should be a base64-encoded JSON Web Key.
 @param directoryServerRootCertificates The root certificates of the directory server to use during the transaction creation phase. The value of this property should be a JSON Web Signature compact serialization.
 */
- (instancetype)initWithDirectoryServerIdentifier: (nonnull NSString*)directoryServerIdentifier
                         directoryServerPublicKey: (nonnull NSString*)directoryServerPublicKey
                  directoryServerRootCertificates: (nonnull NSString*)directoryServerRootCertificates;

@end

NS_ASSUME_NONNULL_END
