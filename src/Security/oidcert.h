
#include <Security/cssmtype.h>

extern "C" {

extern const CSSM_OID CSSMOID_X509V3SignedCertificate;
extern const CSSM_OID CSSMOID_X509V3SignedCertificateCStruct;
extern const CSSM_OID CSSMOID_X509V3Certificate;
extern const CSSM_OID CSSMOID_X509V3CertificateCStruct;
extern const CSSM_OID CSSMOID_X509V1Version;
extern const CSSM_OID CSSMOID_X509V1SerialNumber;
extern const CSSM_OID CSSMOID_X509V1IssuerName;
extern const CSSM_OID CSSMOID_X509V1IssuerNameStd;
extern const CSSM_OID CSSMOID_X509V1IssuerNameCStruct;
extern const CSSM_OID CSSMOID_X509V1IssuerNameLDAP;
extern const CSSM_OID CSSMOID_X509V1ValidityNotBefore;
extern const CSSM_OID CSSMOID_X509V1ValidityNotAfter;
extern const CSSM_OID CSSMOID_X509V1SubjectName;
extern const CSSM_OID CSSMOID_X509V1SubjectNameStd;
extern const CSSM_OID CSSMOID_X509V1SubjectNameCStruct;
extern const CSSM_OID CSSMOID_X509V1SubjectNameLDAP;
extern const CSSM_OID CSSMOID_CSSMKeyStruct;
extern const CSSM_OID CSSMOID_X509V1SubjectPublicKeyCStruct;
extern const CSSM_OID CSSMOID_X509V1SubjectPublicKeyAlgorithm;
extern const CSSM_OID CSSMOID_X509V1SubjectPublicKeyAlgorithmParameters;
extern const CSSM_OID CSSMOID_X509V1SubjectPublicKey;
extern const CSSM_OID CSSMOID_X509V1CertificateIssuerUniqueId;
extern const CSSM_OID CSSMOID_X509V1CertificateSubjectUniqueId;
extern const CSSM_OID CSSMOID_X509V3CertificateExtensionsStruct;
extern const CSSM_OID CSSMOID_X509V3CertificateExtensionsCStruct;
extern const CSSM_OID CSSMOID_X509V3CertificateNumberOfExtensions;
extern const CSSM_OID CSSMOID_X509V3CertificateExtensionStruct;
extern const CSSM_OID CSSMOID_X509V3CertificateExtensionCStruct;
extern const CSSM_OID CSSMOID_X509V3CertificateExtensionId;
extern const CSSM_OID CSSMOID_X509V3CertificateExtensionCritical;
extern const CSSM_OID CSSMOID_X509V3CertificateExtensionType;
extern const CSSM_OID CSSMOID_X509V3CertificateExtensionValue;
extern const CSSM_OID CSSMOID_X509V1SignatureStruct;
extern const CSSM_OID CSSMOID_X509V1SignatureCStruct;
extern const CSSM_OID CSSMOID_X509V1SignatureAlgorithm;
extern const CSSM_OID CSSMOID_X509V1SignatureAlgorithmTBS;
extern const CSSM_OID CSSMOID_X509V1SignatureAlgorithmParameters;
extern const CSSM_OID CSSMOID_X509V1Signature;
extern const CSSM_OID CSSMOID_SubjectSignatureBitmap;
extern const CSSM_OID CSSMOID_SubjectPicture;
extern const CSSM_OID CSSMOID_SubjectEmailAddress;
extern const CSSM_OID CSSMOID_UseExemptions;
extern const CSSM_OID CSSMOID_SubjectDirectoryAttributes;
extern const CSSM_OID CSSMOID_SubjectKeyIdentifier;
extern const CSSM_OID CSSMOID_KeyUsage;
extern const CSSM_OID CSSMOID_PrivateKeyUsagePeriod;
extern const CSSM_OID CSSMOID_SubjectAltName;
extern const CSSM_OID CSSMOID_IssuerAltName;
extern const CSSM_OID CSSMOID_BasicConstraints;
extern const CSSM_OID CSSMOID_CrlNumber;
extern const CSSM_OID CSSMOID_CrlReason;
extern const CSSM_OID CSSMOID_HoldInstructionCode;
extern const CSSM_OID CSSMOID_InvalidityDate;
extern const CSSM_OID CSSMOID_DeltaCrlIndicator;
extern const CSSM_OID CSSMOID_IssuingDistributionPoint;
extern const CSSM_OID CSSMOID_IssuingDistributionPoints;
extern const CSSM_OID CSSMOID_CertIssuer;
extern const CSSM_OID CSSMOID_NameConstraints;
extern const CSSM_OID CSSMOID_CrlDistributionPoints;
extern const CSSM_OID CSSMOID_CertificatePolicies;
extern const CSSM_OID CSSMOID_PolicyMappings;
extern const CSSM_OID CSSMOID_PolicyConstraints;
extern const CSSM_OID CSSMOID_AuthorityKeyIdentifier;
extern const CSSM_OID CSSMOID_ExtendedKeyUsage;
extern const CSSM_OID CSSMOID_InhibitAnyPolicy;
extern const CSSM_OID CSSMOID_AuthorityInfoAccess;
extern const CSSM_OID CSSMOID_BiometricInfo;
extern const CSSM_OID CSSMOID_QC_Statements;
extern const CSSM_OID CSSMOID_SubjectInfoAccess;
extern const CSSM_OID CSSMOID_ExtendedKeyUsageAny;
extern const CSSM_OID CSSMOID_ServerAuth;
extern const CSSM_OID CSSMOID_ClientAuth;
extern const CSSM_OID CSSMOID_ExtendedUseCodeSigning;
extern const CSSM_OID CSSMOID_EmailProtection;
extern const CSSM_OID CSSMOID_TimeStamping;
extern const CSSM_OID CSSMOID_OCSPSigning;
extern const CSSM_OID CSSMOID_KERBv5_PKINIT_KP_CLIENT_AUTH;
extern const CSSM_OID CSSMOID_KERBv5_PKINIT_KP_KDC;
extern const CSSM_OID CSSMOID_EKU_IPSec;
extern const CSSM_OID CSSMOID_DOTMAC_CERT_EXTENSION;
extern const CSSM_OID CSSMOID_DOTMAC_CERT_IDENTITY;
extern const CSSM_OID CSSMOID_DOTMAC_CERT_EMAIL_SIGN;
extern const CSSM_OID CSSMOID_DOTMAC_CERT_EMAIL_ENCRYPT;
extern const CSSM_OID CSSMOID_APPLE_CERT_POLICY;
extern const CSSM_OID CSSMOID_DOTMAC_CERT_POLICY;
extern const CSSM_OID CSSMOID_ADC_CERT_POLICY;
extern const CSSM_OID CSSMOID_MACAPPSTORE_CERT_POLICY;
extern const CSSM_OID CSSMOID_MACAPPSTORE_RECEIPT_CERT_POLICY;
extern const CSSM_OID CSSMOID_APPLEID_CERT_POLICY;
extern const CSSM_OID CSSMOID_APPLEID_SHARING_CERT_POLICY;
extern const CSSM_OID CSSMOID_APPLE_EKU_CODE_SIGNING;
extern const CSSM_OID CSSMOID_APPLE_EKU_CODE_SIGNING_DEV;
extern const CSSM_OID CSSMOID_APPLE_EKU_RESOURCE_SIGNING;
extern const CSSM_OID CSSMOID_APPLE_EKU_ICHAT_SIGNING;
extern const CSSM_OID CSSMOID_APPLE_EKU_ICHAT_ENCRYPTION;
extern const CSSM_OID CSSMOID_APPLE_EKU_SYSTEM_IDENTITY;
extern const CSSM_OID CSSMOID_APPLE_EXTENSION;
extern const CSSM_OID CSSMOID_APPLE_EXTENSION_CODE_SIGNING;
extern const CSSM_OID CSSMOID_APPLE_EXTENSION_APPLE_SIGNING;
extern const CSSM_OID CSSMOID_APPLE_EXTENSION_ADC_DEV_SIGNING;
extern const CSSM_OID CSSMOID_APPLE_EXTENSION_ADC_APPLE_SIGNING;
extern const CSSM_OID CSSMOID_APPLE_EXTENSION_MACAPPSTORE_RECEIPT;
extern const CSSM_OID CSSMOID_APPLE_EXTENSION_INTERMEDIATE_MARKER;
extern const CSSM_OID CSSMOID_APPLE_EXTENSION_WWDR_INTERMEDIATE;
extern const CSSM_OID CSSMOID_APPLE_EXTENSION_ITMS_INTERMEDIATE;
extern const CSSM_OID CSSMOID_APPLE_EXTENSION_AAI_INTERMEDIATE;
extern const CSSM_OID CSSMOID_APPLE_EXTENSION_APPLEID_INTERMEDIATE;
extern const CSSM_OID CSSMOID_APPLE_EXTENSION_APPLEID_SHARING;
extern const CSSM_OID CSSMOID_NetscapeCertType;
extern const CSSM_OID CSSMOID_NetscapeCertSequence;
extern const CSSM_OID CSSMOID_NetscapeSGC;
extern const CSSM_OID CSSMOID_MicrosoftSGC;

}